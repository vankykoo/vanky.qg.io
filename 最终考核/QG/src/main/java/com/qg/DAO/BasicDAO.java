package com.qg.DAO;

import com.qg.util.JDBCUtils;

import java.sql.*;

/**
 * BasicDAO相当于CRUDUtils
 * @author vanky
 */
public class BasicDAO<T> {
    private Connection connection;
    private PreparedStatement preparedStatement;
    private JDBCUtils jdbcUtils = new JDBCUtils();

    //增删改数据
    public void update(String sql,Object... params){
        //获取连接
        connection = jdbcUtils.getConnection();
        //获取PreparedStatement
        try {
            preparedStatement = connection.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                if(params[i] instanceof Integer){
                    preparedStatement.setInt(i+1,(int)params[i]);
                }else if(params[i] instanceof String){
                    preparedStatement.setString(i+1,(String)params[i]);
                }else{
                    preparedStatement.setDate(i+1,(Date)params[i]);
                }
            }
            //执行sql语句，可以返回受影响的行数
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,connection);
        }
    }

    //查找数据
    public ResultSet select(String sql, Class<T> clazz, Object... params){
        //获取连接
        connection = jdbcUtils.getConnection();
        //获取PreparedStatement
        try {
            preparedStatement = connection.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                if(params[i] instanceof Integer){
                    preparedStatement.setInt(i+1,(int)params[i]);
                }else if(params[i] instanceof String){
                    preparedStatement.setString(i+1,(String)params[i]);
                }else{
                    preparedStatement.setDate(i+1,(Date)params[i]);
                }
            }
            //执行sql语句,返回数据
            ResultSet resultSet = preparedStatement.executeQuery();
            return resultSet;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,connection);
        }
    }
}
