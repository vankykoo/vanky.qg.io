package com.qg.service;

import com.qg.pojo.Notice;

import java.util.List;

public interface NoticeService {
    /**
     * 查看所有通知
     * @param getterId
     * @return
     */
    List<Notice> selectAllNotice(Integer getterId);

    /**
     * 添加新的通知
     * @param notice
     */
    void addNotice(Notice notice);
}
