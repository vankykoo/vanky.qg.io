package com.qg.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;

public class ConnectionPool {
    private ArrayList<Connection> connections = new ArrayList<>();
    private String url;
    private String user;
    private String password;
    private String driver;
    private final Object lock = new Object();

    public ConnectionPool(String url, String user, String password, String driver) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.driver = driver;
    }

    //获取连接
    public Connection getConnection() throws SQLException, ClassNotFoundException {
        synchronized (lock) {
            if (connections.isEmpty()) {
                Class.forName(driver);
                Connection connection = DriverManager.getConnection(url, user, password);
                return connection;
            } else {
                return connections.remove(connections.size() - 1);
            }
        }
    }
    //释放连接
    public void releaseConnection(Connection connection){
        synchronized (lock) {
            connections.add(connection);
        }
    }
}
