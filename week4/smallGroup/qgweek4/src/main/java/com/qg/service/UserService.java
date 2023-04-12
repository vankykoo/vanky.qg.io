package com.qg.service;

import com.qg.pojo.User;

public interface UserService {

    /**
     * 查询用户是否存在
     * @param userName
     * @return
     */
    User select(String userName);

    /**
     * 注册
     * @param user
     */
    void add(User user);
}
