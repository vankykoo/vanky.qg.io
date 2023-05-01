package com.qg.service.Impl;

import com.qg.DAO.CommentDAO;
import com.qg.pojo.Comment;
import com.qg.service.CommentService;

import java.util.List;

public class CommentServiceImpl implements CommentService {
    CommentDAO commentDAO = new CommentDAO();
    @Override
    public void remarkByGoodsId(Comment comment) {
        commentDAO.remarkByGoodsId(comment);
    }

    @Override
    public List<Comment> selectCommentByGoodsId(Integer goodsId) {
        return commentDAO.selectCommentByGoodsId(goodsId);
    }

    @Override
    public void deleteByCommentId(Integer commentId) {
        commentDAO.deleteByCommentId(commentId);
    }
}
