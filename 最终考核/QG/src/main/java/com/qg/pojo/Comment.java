package com.qg.pojo;

public class Comment {
    //评论id
    private Integer commentId;
    //商品id
    private Integer goodsId;
    //评分
    private String grade;
    //评论内容
    private String description;
    //用户Id
    private Integer userId;

    public Comment(Integer commentId, Integer goodsId, String grade, String description, Integer userId) {
        this.commentId = commentId;
        this.goodsId = goodsId;
        this.grade = grade;
        this.description = description;
        this.userId = userId;
    }

    public Integer getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(Integer goodsId) {
        this.goodsId = goodsId;
    }

    public String getGrade() {
        return grade;
    }

    public void setGrade(String grade) {
        this.grade = grade;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Integer getCommentId() {
        return commentId;
    }

    public void setCommentId(Integer commentId) {
        this.commentId = commentId;
    }

    public Integer getUserId() {
        return userId;
    }

    public void setUserId(Integer userId) {
        this.userId = userId;
    }

    @Override
    public String toString() {
        return "Comment{" +
                "commentId=" + commentId +
                ", goodsId=" + goodsId +
                ", grade='" + grade + '\'' +
                ", description='" + description + '\'' +
                ", userId=" + userId +
                '}';
    }
}
