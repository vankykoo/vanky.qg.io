package com.qg.demo;

import com.qg.dao.StudentDAO;
import com.qg.pojo.Student;

import java.util.List;

/**
 * @author vanky
 */
public class TestDAO {


    /**
     * 增删改查student表
     */
    public static void main(String[] args){

        StudentDAO studentDAO = new StudentDAO();
        //1. 查询
        List<Student> students = studentDAO.queryMulti("select * from student where id >= ?", Student.class, 1);
        System.out.println("查询结果:");
        for (Student student : students) {
            System.out.println(student);
        }

        //2. 查询单行记录
        Student student = studentDAO.querySingle("select * from student where id = ?", Student.class, 6);
        System.out.println("查询单行结果:");
        System.out.println(student);

        //3. 查询单行单列
        Object o = studentDAO.queryScalar("select name from student where id = ?", 6);
        System.out.println("查询单行单列结果:");
        System.out.println(o);

        //4. 增删改操作（dml
        int update1 = studentDAO.update("insert into student values(?, ?, ?, ?, ?)", 8,"文奇", 91, 120, 99);
        System.out.println("影响的行数为：" + update1);

//        int update2 = studentDAO.update("update student set name = ? where id = 8","里奥");
//        System.out.println(update2 > 0 ? "修改成员执行成功" : "修改成员执行没有影响表");

//        int update3 = studentDAO.update("delete from student where id = 8");
//        System.out.println(update3 > 0 ? "删除成员执行成功" : "删除成员执行没有影响表");



    }
}
