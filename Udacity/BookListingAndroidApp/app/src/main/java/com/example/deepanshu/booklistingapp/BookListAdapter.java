package com.example.deepanshu.booklistingapp;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.deepanshu.booklistingapp.custom.TextView_Lato;
import com.example.deepanshu.booklistingapp.custom.Textview_lato_thin;
import com.example.deepanshu.booklistingapp.service.ImageLoadTask;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import de.hdodenhof.circleimageview.CircleImageView;

/**
 * Created by deepanshu on 30/3/17.
 */

class BookListAdapter extends RecyclerView.Adapter<BookListAdapter.MyViewHolder> {

    private List<BookList> mBookLists;

    BookListAdapter(ArrayList<BookList> mBookArrayList) {
        this.mBookLists = mBookArrayList;
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        return new MyViewHolder(LayoutInflater.from(parent.getContext())
                .inflate(R.layout.inflater_book_list_row, parent, false));
    }

    BookList getItem(int position) {
        return mBookLists.get(position);
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {
        BookList bookList = getItem(position);
        new ImageLoadTask(bookList.getThumbnail(), holder.mBookIcon).execute();
        holder.mBookName.setText(bookList.getTitle());
        holder.mBookInfo.setText(Arrays.toString(bookList.getAuthors()).replace("[", "").replace("]", ""));
    }

    @Override
    public int getItemCount() {
        return mBookLists.size();
    }

    void clear() {
        if (null != mBookLists && mBookLists.size() > 0) {
            this.mBookLists.clear();
            this.notifyItemRangeRemoved(0, mBookLists.size());
        }
    }

    void addAll(ArrayList<BookList> bookArrayList) {
        this.mBookLists = bookArrayList;
        this.notifyDataSetChanged();
    }

    class MyViewHolder extends RecyclerView.ViewHolder {

        private CircleImageView mBookIcon;
        private TextView_Lato mBookName;
        private Textview_lato_thin mBookInfo;

        MyViewHolder(View itemView) {
            super(itemView);
            mBookIcon = (CircleImageView) itemView.findViewById(R.id.book_image);
            mBookName = (TextView_Lato) itemView.findViewById(R.id.book_name);
            mBookInfo = (Textview_lato_thin) itemView.findViewById(R.id.book_info);
        }
    }
}
