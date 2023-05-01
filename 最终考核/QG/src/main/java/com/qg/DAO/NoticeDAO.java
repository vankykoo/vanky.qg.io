package com.qg.DAO;

import com.qg.pojo.Notice;
import com.qg.util.JDBCUtils;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author vanky
 */
public class NoticeDAO extends BasicDAO<Notice> {
    JDBCUtils jdbcUtils = new JDBCUtils();

    public List<Notice> selectAllNotice(Integer getterId){
        Notice notice = null;
        List<Notice> noticeList = new ArrayList<>();
        String sql = "select * from tb_notice where notice_getter_id =?";
        ResultSet resultSet = select(sql, Notice.class, getterId);
        try {
            while (resultSet.next()){
                String noticeTime = resultSet.getString(1);
                String noticeTimeString = noticeTime.toString();
                String content = resultSet.getString(2);
                notice = new Notice(noticeTimeString,content,getterId);
                noticeList.add(notice);
            }
            return noticeList;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            jdbcUtils.close(null,null,null);
        }
    }

    public void addNotice(Notice notice){
        String sql = "insert into tb_notice (notice_time,notice_content," +
                "notice_getter_id) values (?,?,?)";
        update(sql,notice.getNoticeTime(),notice.getNoticeContent(),notice.getGetterId());
    }
}
