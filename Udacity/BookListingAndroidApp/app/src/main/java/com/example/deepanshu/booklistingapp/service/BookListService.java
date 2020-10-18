package com.example.deepanshu.booklistingapp.service;

import com.example.deepanshu.booklistingapp.BookList;

import java.util.ArrayList;

/**
 * Created by deepanshu on 2/4/17.
 */

public interface BookListService {
    void onPostExecute(ArrayList<BookList> bookArrayList);
}
