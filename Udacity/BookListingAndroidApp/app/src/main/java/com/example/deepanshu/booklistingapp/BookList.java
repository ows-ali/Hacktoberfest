package com.example.deepanshu.booklistingapp;

import android.os.Parcel;
import android.os.Parcelable;

import java.util.Arrays;

/**
 * Created by deepanshu on 2/4/17.
 */

public class BookList implements Parcelable {

    private String title;
    private String[] authors;
    private String thumbnail;

    public BookList(String title, String[] authors, String thumbnail) {
        this.setTitle(title);
        this.setAuthors(authors);
        this.setThumbnail(thumbnail);
    }

    @Override
    public String toString() {
        return "Book{" +
                "title='" + getTitle() + '\'' +
                ", authors=" + Arrays.toString(getAuthors()) +
                '}';
    }

    String getTitle() {
        return title;
    }

    private void setTitle(String title) {
        this.title = title;
    }

    String[] getAuthors() {
        return authors;
    }

    private void setAuthors(String[] authors) {
        this.authors = authors;
    }

    String getThumbnail() {
        return thumbnail;
    }

    private void setThumbnail(String thumbnail) {
        this.thumbnail = thumbnail;
    }

    private BookList(Parcel in) {
        title = in.readString();
        thumbnail = in.readString();
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(title);
        dest.writeString(thumbnail);
    }

    @SuppressWarnings("unused")
    public static final Parcelable.Creator<BookList> CREATOR = new Parcelable.Creator<BookList>() {
        @Override
        public BookList createFromParcel(Parcel in) {
            return new BookList(in);
        }

        @Override
        public BookList[] newArray(int size) {
            return new BookList[size];
        }
    };
}
