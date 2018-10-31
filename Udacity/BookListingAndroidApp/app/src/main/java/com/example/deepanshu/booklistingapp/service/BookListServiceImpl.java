package com.example.deepanshu.booklistingapp.service;

import android.os.AsyncTask;
import android.util.Log;

import com.example.deepanshu.booklistingapp.BookList;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;

/**
 * Created by deepanshu on 2/4/17.
 */

public class BookListServiceImpl extends AsyncTask<String, Void, ArrayList<BookList>> {

    private final static String LOG_TAG = BookListServiceImpl.class.getSimpleName();

    private static final String ITEMS = "items";
    private static final String VOLUME_INFO = "volumeInfo";
    private static final String TITLE = "title";
    private static final String AUTHORS = "authors";

    private BookListService mBookListService = null;

    public BookListServiceImpl(BookListService listService) {
        this.mBookListService = listService;
    }

    @Override
    protected ArrayList<BookList> doInBackground(String... params) {
        HttpURLConnection urlConnection = null;
        BufferedReader reader = null;

        // Will contain the raw JSON response as a string.
        String bookJsonStr = null;

        try {
            // Construct the URL for the Google Books API query
            URL url = new URL(params[0]);

            // Create the request to Google Books API, and open the connection
            urlConnection = (HttpURLConnection) url.openConnection();
            urlConnection.setRequestMethod("GET");
            urlConnection.connect();

            // Read the input stream into a String
            InputStream inputStream = urlConnection.getInputStream();
            StringBuilder buffer = new StringBuilder();
            if (null == inputStream) {
                // Nothing to do.
                bookJsonStr = null;
            }
            if (inputStream != null) {
                reader = new BufferedReader(new InputStreamReader(inputStream));

                String line;
                while ((line = reader.readLine()) != null) {
                    // Since it's JSON, adding a newline isn't necessary (it won't affect parsing)
                    // But it does make debugging a *lot* easier if you print out the completed
                    // buffer for debugging.
                    buffer.append(line).append("\n");
                }
            }

            if (buffer.length() == 0) {
                // Stream was empty.  No point in parsing.
                bookJsonStr = null;
            }
            bookJsonStr = buffer.toString();
        } catch (IOException e) {
            Log.e(LOG_TAG, "Error ", e);
            // If the code didn't successfully get the book list data, there's no point in attempting
            // to parse it.
            bookJsonStr = null;
        } finally {
            if (urlConnection != null) {
                urlConnection.disconnect();
            }
            if (reader != null) {
                try {
                    reader.close();
                } catch (final IOException e) {
                    Log.e(LOG_TAG, "Error closing stream", e);
                }
            }
        }
        return jsonConvertor(bookJsonStr);
    }

    @Override
    protected void onPostExecute(ArrayList<BookList> bookLists) {
        mBookListService.onPostExecute(bookLists);
    }

    private ArrayList<BookList> jsonConvertor(String bookJsonStr) {
        ArrayList<BookList> bookArrayList = new ArrayList<>();

        try {
            JSONObject bookJsonObject = new JSONObject(bookJsonStr);
            if (!bookJsonObject.isNull(ITEMS)) {

                JSONArray bookJsonArray = bookJsonObject.getJSONArray(ITEMS);

                for (int i = 0; i < bookJsonArray.length(); i++) {

                    JSONObject itemJsonObject = bookJsonArray.getJSONObject(i);
                    JSONObject volumeInfoObject = itemJsonObject.getJSONObject(VOLUME_INFO);

                    String title = volumeInfoObject.getString(TITLE);

                    String[] authors = new String[]{"No Authors"};

                    if (!volumeInfoObject.isNull(AUTHORS)) {
                        JSONArray authorsArray = volumeInfoObject.getJSONArray(AUTHORS);
                        Log.d(LOG_TAG, "authors #" + authorsArray.length());
                        authors = new String[authorsArray.length()];
                        for (int j = 0; j < authorsArray.length(); j++) {
                            authors[j] = authorsArray.getString(j);
                        }
                    }

                    // Json parsing for image
                    JSONObject imageLinks = volumeInfoObject.getJSONObject("imageLinks");
                    String thumbnail = imageLinks.getString("thumbnail");
                    Log.e(LOG_TAG, "jsonConvertor: " + thumbnail);

                    bookArrayList.add(new BookList(title, authors, thumbnail));
                }
            } else {
                bookArrayList = null;
            }
        } catch (JSONException e) {
            Log.d(LOG_TAG, e.toString());
        }
        return bookArrayList;
    }
}
