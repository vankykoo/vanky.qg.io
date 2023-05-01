package com.qg.web;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;


/**
 * replace HttpServlet, according request path tail, decide which method be invoked
 */

public class BaseServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        String URI = req.getRequestURI();
        int index = URI.lastIndexOf('/');
        String methodName = URI.substring(index + 1);

        /**
         * 得到了方法的名称，它是一个字符串，无法调用，
         * 我们必须获取servlet的Class文件，然后才能调用该方法，
         * 我们可以通过以下方法获得Class文件，然后我们调用方法
         */

        Class<? extends BaseServlet> cls = this.getClass();
        try {
            Method method = cls.getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            method.invoke(this,req,resp);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

    }
}
