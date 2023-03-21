package com.qg.poolUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

@SuppressWarnings({"ALL"})
public class Test {

    public static void main(String[] args) throws SQLException {
        PoolImpl pool = new PoolImpl();
        for(int i = 0; i < 100; i++) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    for (int j = 0; j < 10; j++) {
                        Connection connection = null;
                        try {
                            connection = pool.getPoolConnection();
                            Statement statement = connection.createStatement();
                            String sql = "select * from student";
                            ResultSet resultSet = statement.executeQuery(sql);
                            synchronized (resultSet) {
                                System.out.println("线程 : [" + Thread.currentThread().getName() + "] 执行SQL, 开始读取返回值");
                                while(resultSet.next()){
                                    resultSet.getString(5);
                                }
                            }
                        } catch (SQLException | InterruptedException e) {
                            e.printStackTrace();
                        } finally {
                            pool.releaseConnection(connection);
                        }
                    }
                }
            }, "Pool-" + i).start();
        }
    }
}

