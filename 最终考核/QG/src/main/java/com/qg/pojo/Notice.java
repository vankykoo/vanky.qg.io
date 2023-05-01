package com.qg.pojo;

/**
 * @author vanky
 */
public class Notice {
    //通知时间
    private String noticeTime;
    //通知内容
    private String noticeContent;
    //接收人id
    private Integer getterId;

    public Notice(String noticeTime, String noticeContent, Integer getterId) {
        this.noticeTime = noticeTime;
        this.noticeContent = noticeContent;
        this.getterId = getterId;
    }

    public String getNoticeTime() {
        return noticeTime;
    }

    public void setNoticeTime(String noticeTime) {
        this.noticeTime = noticeTime;
    }

    public String getNoticeContent() {
        return noticeContent;
    }

    public void setNoticeContent(String noticeContent) {
        this.noticeContent = noticeContent;
    }

    public Integer getGetterId() {
        return getterId;
    }

    public void setGetterId(Integer getterId) {
        this.getterId = getterId;
    }

    @Override
    public String toString() {
        return "Notice{" +
                "noticeTime='" + noticeTime + '\'' +
                ", noticeContent='" + noticeContent + '\'' +
                ", getterId=" + getterId +
                '}';
    }
}
