package com.qg.service;

import com.qg.pojo.User;

public interface UserService {
    //查找用户是否已被注册
    User select(String userName);

    //用ID查找
    User selectById(Integer userId);

    //注册
    void register(User user);

    //修改资料
    void editUserData(User user);

    /**
     * 开店铺
     * @param userId
     */
    void openStore(Integer userId);

    /**
     * 查找店主
     * @param storeId
     * @return
     */
    User selectUserByStoreId(Integer storeId);
}
