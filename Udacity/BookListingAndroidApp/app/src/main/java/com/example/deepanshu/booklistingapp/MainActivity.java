package com.example.deepanshu.booklistingapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.Toast;

import com.example.deepanshu.booklistingapp.custom.RecyclerItemClickListener;
import com.example.deepanshu.booklistingapp.custom.TextView_Lato;
import com.example.deepanshu.booklistingapp.service.BookListService;
import com.example.deepanshu.booklistingapp.service.BookListServiceImpl;
import com.example.deepanshu.booklistingapp.utility.Utility;
import com.mancj.materialsearchbar.MaterialSearchBar;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements MaterialSearchBar.OnSearchActionListener {

    private static final String BOOK_LIST = "list_of_books";

    private RecyclerView mRecyclerView;
    private TextView_Lato mTextViewMsg;
    private BookListAdapter mBookListAdapter;
    private ArrayList<BookList> mBookArrayList = new ArrayList<>();

    public static final String GOOGLE_BOOKS_API_BASE_QUERY = "https://www.googleapis.com/books/v1/volumes?maxResults=20&key=AIzaSyC5gSOScPvSCrPssIez0VRSPXHfDsH7bUY&q=";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mRecyclerView = (RecyclerView) findViewById(R.id.book_list_rcv);
        mRecyclerView.setLayoutManager(new LinearLayoutManager(this));

        mTextViewMsg = (TextView_Lato) findViewById(R.id.message);

        MaterialSearchBar searchBar = (MaterialSearchBar) findViewById(R.id.searchBar);
        searchBar.setHint(getString(R.string.book_hint_name));

        //enable searchbar callbacks
        searchBar.setOnSearchActionListener(this);

        mRecyclerView.setAdapter(mBookListAdapter = new BookListAdapter(mBookArrayList));

        mRecyclerView.addOnItemTouchListener(new RecyclerItemClickListener(this, new RecyclerItemClickListener.OnItemClickListener() {
            @Override
            public void onItemClick(View view, int position) {
                Toast.makeText(MainActivity.this, mBookListAdapter.getItem(position).toString(), Toast.LENGTH_SHORT).show();
            }
        }));
    }

    @Override
    public void onSearchStateChanged(boolean enabled) {
    }

    @Override
    public void onSearchConfirmed(CharSequence text) {
        callBookListApi(text.toString());
    }

    @Override
    public void onButtonClicked(int buttonCode) {

    }

    public void callBookListApi(String query) {

        String searchQuery = query.replaceAll(" ", "+");
        if (null != searchQuery && !searchQuery.equals("")) {

            String searchString = GOOGLE_BOOKS_API_BASE_QUERY + searchQuery;

            if (Utility.isNetworkAvailable(this)) {
                BookListServiceImpl mBookListServiceImpl = new BookListServiceImpl(new BookListService() {
                    @Override
                    public void onPostExecute(ArrayList<BookList> bookArrayList) {

                        setViews(mBookArrayList = bookArrayList);
                    }
                });

                mBookListServiceImpl.execute(searchString);
            } else {
                // No Internet Connection
                Toast.makeText(this, R.string.no_connection, Toast.LENGTH_SHORT).show();
            }
        } else {
            Toast.makeText(this, R.string.no_data, Toast.LENGTH_SHORT).show();
        }
    }

    private void setViews(ArrayList<BookList> mBookArrayList) {

        if (mBookArrayList != null && mBookArrayList.size() > 0) {
            setList();
            mBookListAdapter.clear();
            mBookListAdapter.addAll(mBookArrayList);
        } else {
            setMessage();
        }
    }

    private void setMessage() {
        mTextViewMsg.setVisibility(View.VISIBLE);
        mRecyclerView.setVisibility(View.GONE);
    }

    private void setList() {
        mRecyclerView.setVisibility(View.VISIBLE);
        mTextViewMsg.setVisibility(View.GONE);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);

        if (null != savedInstanceState) {
            setViews(savedInstanceState.<BookList>getParcelableArrayList(BOOK_LIST));
        }
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        // Save the user's current game state
        outState.putParcelableArrayList(BOOK_LIST, mBookArrayList);

        // Always call the superclass so it can save the view hierarchy state
        super.onSaveInstanceState(outState);
    }
}
