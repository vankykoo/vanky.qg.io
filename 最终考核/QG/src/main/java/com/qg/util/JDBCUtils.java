package com.qg.util;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils{
    private static String user; //用户名
    private static String password; //密码
    private static String url; //url
    private static String driver; //驱动名
    private static ConnectionPool connectionPool;

    //使用静态代码块初始化
    static {
        Properties properties = new Properties();
        try {
            properties.load(new FileInputStream("C:\\Users\\86180\\IdeaProjects\\QG\\src\\main\\resources\\mysql.properties"));
            //读取相关的属性值
            user = properties.getProperty("user");
            password = properties.getProperty("password");
            url = properties.getProperty("url");
            driver = properties.getProperty("driver");
            connectionPool = new ConnectionPool(url,user,password,driver);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    //连接数据库方法，返回Connection
    public Connection getConnection() {
        try {
            return connectionPool.getConnection();
        } catch (SQLException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    //关闭资源的方法
    public void close(ResultSet set, Statement statement, Connection connection){
        try {
            if (set != null) {
                set.close();
            }
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                //放回连接池
                connectionPool.releaseConnection(connection);
            }
        } catch (SQLException e) {
            //将编译异常转成运行异常抛出
            throw new RuntimeException(e);
        }
    }
}
