package com.qg.mapper;

import com.qg.pojo.User;
import org.apache.ibatis.annotations.*;

public interface UserMapper {

    /**
     * 登录功能
     * @param userName
     * @param password
     * @return
     */
    @Select("select * from tb_user where username = #{username} and password = #{password}")
    User login(@Param("username") String userName, @Param("password") String password);
}
