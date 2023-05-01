package com.qg.DAO;

import com.qg.pojo.User;
import com.qg.util.JDBCUtils;

import java.sql.*;

/**
 * @author vanky
 */
public class UserDAO extends BasicDAO<User>{
    JDBCUtils jdbcUtils = new JDBCUtils();
    StoreDAO storeDAO = new StoreDAO();

    //查找用户是否存在：用于注册登录
    public User selectUser(String sql,Object... params) {
        User user = null;

        ResultSet resultSet = select(sql, User.class, params);
        try {
            if (resultSet.next()){
                Integer userId = resultSet.getInt(1);
                String username = resultSet.getNString(2);
                String password = resultSet.getNString(3);
                String userPicture = resultSet.getNString(4);
                String userAddress = resultSet.getNString(5);
                String phoneNumber = resultSet.getNString(6);
                Integer identity = resultSet.getInt(7);
                Integer storeId = resultSet.getInt(8);
                user = new User(userId,username,password,userPicture,userAddress,phoneNumber,identity,storeId);
            }
            return user;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }
    }

    //注册用户
    public void addUser(User user){
        if (user.getUserPicture() == null){
            user.setUserPicture("https://cube.elemecdn.com/9/c2/f0ee8a3c7c9638a54940382568c9dpng.png");
        }
        //sql语句
        String sql = "insert into tb_user (user_name, password, user_picture, " +
                "user_address, phoneNumber,identity,user_store_id) " +
                "values (?,?,?,?,?,?,?)";
        update(sql,user.getUserName(),user.getPassword(),user.getUserPicture(),
                user.getUserAddress(),user.getPhoneNumber(),1,0);
    }

    public void editUserData(User user){
        String sql = "update tb_user set user_name =?,user_picture =?,user_address =?,phoneNumber =? " +
                "where user_id =?";
        update(sql,user.getUserName(),user.getUserPicture(),user.getUserAddress(),user.getPhoneNumber(),user.getUserId());
    }

    public void openStore(Integer userId){
        String sql = "update tb_user set user_store_id =? where user_id =?";
        Integer storeId = storeDAO.getStoreId();
        update(sql,storeId,userId);
    }
}
