package com.qg.service;

import com.qg.pojo.User;

public interface UserService {

    /**
     * 登录功能
     * @param userName
     * @param password
     * @return
     */
    User login(String userName, String password);

}
