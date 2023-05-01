package com.qg.service;

import com.qg.pojo.Comment;

import java.util.List;

public interface CommentService {

    /**
     * 给商品评论
     * @param comment
     */
    void remarkByGoodsId(Comment comment);

    /**
     * 查看商品评论
     * @param goodsId
     * @return
     */
    List<Comment> selectCommentByGoodsId(Integer goodsId);

    /**
     * 删除评论
     * @param commentId
     */
    void deleteByCommentId(Integer commentId);

}
