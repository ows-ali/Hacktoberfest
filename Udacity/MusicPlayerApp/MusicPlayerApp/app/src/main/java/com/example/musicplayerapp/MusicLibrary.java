package com.example.musicplayerapp;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MusicLibrary extends AppCompatActivity {

    ListView musicList;
    String itemClicked;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_music_library);

        RelativeLayout lib_parent = findViewById(R.id.library_rel);
        musicList = findViewById(R.id.music_list);

        AnimationDrawable animationDrawable = (AnimationDrawable) lib_parent.getBackground();

        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(2000);

        animationDrawable.start();

        ArrayList<String> song_list = new ArrayList<String>();
        song_list.add("Apocalypse");
        song_list.add("Can't Help Falling");
        song_list.add("Coffee Shop");
        song_list.add("La Vie En Rose");
        song_list.add("The One");

        // This is the array adapter, it takes the context of the activity as a
        // first parameter, the type of list view as a second parameter and your
        // array as a third parameter.

        LibraryAdapter libraryAdapter = new LibraryAdapter(getApplicationContext(), song_list);
        musicList.setAdapter(libraryAdapter);

        musicList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view,int position, long id) {
                itemClicked = (String) musicList.getItemAtPosition(position);
                Intent intent = new Intent(MusicLibrary.this, NowPlaying.class);
                intent.putExtra("Song Selected", itemClicked);
                startActivity(intent);
            }
        });

    }
}
