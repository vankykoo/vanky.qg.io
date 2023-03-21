package com.qg.poolUtils;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.LinkedList;

public class PoolImpl implements IPool {
    //  定义一个链表存放连接池连接
    private LinkedList<Connection> pools = new LinkedList<>();

    public PoolImpl() {
        // 初始化连接池信息
        init();
        System.out.println("连接池初始化成功");
    }

    private void init() {
        try {
            Driver driver = (Driver) Class.forName(PoolManager.driver).newInstance();
            DriverManager.registerDriver(driver);
            initConnectionPool();
        } catch (InstantiationException | IllegalAccessException | SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * 初始化链接
     *
     * @throws SQLException sql异常
     */
    private void initConnectionPool() throws SQLException {
        // 初始化连接池数量
        for (int i = 0; i < PoolManager.size; i++) {
            Connection connection = DriverManager.getConnection(PoolManager.url, PoolManager.username, PoolManager.password);
            pools.addLast(connection);
        }
    }

    @Override
    public Connection getPoolConnection() throws InterruptedException {
        // 同步pools
        synchronized (pools) {
            // 非超时等待模式
            if (PoolManager.mills <= 0) {
                while (pools.isEmpty()) {
                    //  会把当前的锁释放，然后让出CPU，进入等待状态
                    pools.wait();
                }
                // 取出链表中头数据
                return pools.removeFirst();
            } else {
                long future = System.currentTimeMillis() + PoolManager.mills;
                long remaining = PoolManager.mills;
                while (pools.isEmpty() && remaining > 0) {
                    // 会把当前的锁释放，然后让出CPU，进入等待状态
                    pools.wait(remaining);
                    remaining = future - System.currentTimeMillis();
                }
                //  获取不到返回null
                return pools.isEmpty() ? null : pools.removeFirst();
            }
        }
    }

    // 释放连接，归还连接
    public void releaseConnection(Connection connection) {
        if (connection != null) {
            synchronized (pools) {
                // 将连接添加到链表的末尾
                pools.addLast(connection);
                // 唤醒所有线程
                pools.notifyAll();
            }
        }
    }
}

