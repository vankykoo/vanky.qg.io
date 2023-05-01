package com.qg.service.Impl;

import com.qg.DAO.NoticeDAO;
import com.qg.pojo.Notice;
import com.qg.service.NoticeService;

import java.util.List;

/**
 * @author vanky
 */
public class NoticeServiceImpl implements NoticeService {
    NoticeDAO noticeDAO = new NoticeDAO();

    @Override
    public List<Notice> selectAllNotice(Integer getterId) {
        return noticeDAO.selectAllNotice(getterId);
    }

    @Override
    public void addNotice(Notice notice) {
        noticeDAO.addNotice(notice);
    }
}
