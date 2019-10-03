package com.example.musicplayerapp;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class GenreAdapter extends ArrayAdapter<String> {

    ArrayList<String> genres;
    public GenreAdapter(Context context, ArrayList<String> arrayList) {
        super(context, 0, arrayList);
        genres = arrayList;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for this position
        String s = getItem(position);
        // Check if an existing view is being reused, otherwise inflate the view
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.list_item, parent, false);
        }
        // Lookup view for data population
        TextView genreName = convertView.findViewById(R.id.genre_title);
        // Populate the data into the template view using the data object
        genreName.setText(s);
        // Return the completed view to render on screen
        return convertView;
    }
}