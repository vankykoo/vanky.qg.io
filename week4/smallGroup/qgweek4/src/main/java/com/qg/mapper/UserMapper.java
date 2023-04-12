package com.qg.mapper;

import com.qg.pojo.User;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

public interface UserMapper {

    /**
     * 查询用户是否存在
     * @param userName
     * @return
     */
    @Select("select * from tb_user where username = #{userName}")
    User select(@Param("userName") String userName);

    /**
     * 注册
     * @param user
     */
    @Insert("insert into tb_user values (null,#{userName},#{password})")
    void add(User user);
}
