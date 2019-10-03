package com.example.musicplayerapp;

import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;

public class ExploreMusic extends AppCompatActivity {

    private ListView genreList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_explore_music);

        RelativeLayout explore_parent = findViewById(R.id.explore_rel);
        genreList = findViewById(R.id.genrelist);

        AnimationDrawable animationDrawable = (AnimationDrawable) explore_parent.getBackground();

        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(2000);

        animationDrawable.start();

        ArrayList<String> genre_list = new ArrayList<String>();
        genre_list.add("Pop");
        genre_list.add("Rock");
        genre_list.add("Indie");
        genre_list.add("K-Pop");
        genre_list.add("Jazz");
        genre_list.add("Metal");
        genre_list.add("Country");
        genre_list.add("Blues");

        // This is the array adapter, it takes the context of the activity as a
        // first parameter, the type of list view as a second parameter and your
        // array as a third parameter.

        GenreAdapter genreAdapter = new GenreAdapter(getApplicationContext(), genre_list);
        genreList.setAdapter(genreAdapter);
    }

}
