package com.qg.dao;

import com.qg.utils.JDBCUtilsByDruid;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;
import org.apache.commons.dbutils.handlers.ScalarHandler;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

/**
 * @author vanky
 */
public class BasicDAO<T> {

    private QueryRunner queryRunner =  new QueryRunner();

    /**
     * dml操作方法
     * @param sql 对应的sql语句
     * @param parameters 给问号（占位符）赋值的参数
     * @return  返回受影响的行数
     */
    public int update(String sql, Object... parameters) {

        Connection connection = null;

        try {
            //用工具类获取连接
            connection = JDBCUtilsByDruid.getConnection();
            //调用queryRunner的update方法
            int update = queryRunner.update(connection, sql, parameters);
            return  update;
        } catch (SQLException e) {
            //将编译异常转换为运行异常后抛出
            throw  new RuntimeException(e);
        } finally {
            //关闭资源
            JDBCUtilsByDruid.close(null, null, connection);
        }

    }


    /**
     *返回多个对象
     * @param sql sql语句
     * @param clazz 传入一个类的.Class对象
     * @param parameters 给问号（占位符）赋值的参数
     * @return 返回对应的 ArrayList 集合
     */
    public List<T> queryMulti(String sql, Class<T> clazz, Object... parameters) {

        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return queryRunner.query(connection, sql, new BeanListHandler<T>(clazz), parameters);

        } catch (SQLException e) {
            throw  new RuntimeException(e);
        } finally {
            JDBCUtilsByDruid.close(null, null, connection);
        }

    }


    /**
     * 查询单行结果
     * @param sql   sql语句
     * @param clazz 一个类的.class对象
     * @param parameters 给占位符赋值的参数
     * @return  返回一个对象
     */
    public T querySingle(String sql, Class<T> clazz, Object... parameters) {

        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return  queryRunner.query(connection, sql, new BeanHandler<T>(clazz), parameters);

        } catch (SQLException e) {
            throw  new RuntimeException(e);
        } finally {
            JDBCUtilsByDruid.close(null, null, connection);
        }
    }


    /**
     * 查询单行单列
     * @param sql sql语句
     * @param parameters 给占位符赋值的参数
     * @return 返回一个值
     */
    public Object queryScalar(String sql, Object... parameters) {

        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return  queryRunner.query(connection, sql, new ScalarHandler(), parameters);

        } catch (SQLException e) {
            throw  new RuntimeException(e);
        } finally {
            JDBCUtilsByDruid.close(null, null, connection);
        }
    }
}
