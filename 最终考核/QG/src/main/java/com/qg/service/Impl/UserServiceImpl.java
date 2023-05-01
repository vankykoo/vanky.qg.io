package com.qg.service.Impl;

import com.qg.DAO.UserDAO;
import com.qg.pojo.User;
import com.qg.service.UserService;

public class UserServiceImpl implements UserService {
    private UserDAO userDAO = new UserDAO();
    /**
     * 查找用户是否存在
     * @param userName
     * @return
     */
    @Override
    public User select(String userName) {
        String sql = "select * from tb_user where user_name =?";
        User user = userDAO.selectUser(sql,userName);

        return user;
    }

    @Override
    public void register(User user) {
        //添加数据到数据库
        userDAO.addUser(user);
    }

    @Override
    public void editUserData(User user) {
        userDAO.editUserData(user);
    }

    @Override
    public void openStore(Integer userId) {
        userDAO.openStore(userId);
    }

    @Override
    public User selectUserByStoreId(Integer storeId) {
        String sql = "select * from tb_user where user_store_id =?";
        return userDAO.selectUser(sql,storeId);
    }

    @Override
    public User selectById(Integer userId) {
        String sql = "select * from tb_user where user_id =?";
        User user = userDAO.selectUser(sql, userId);
        return user;
    }
}
