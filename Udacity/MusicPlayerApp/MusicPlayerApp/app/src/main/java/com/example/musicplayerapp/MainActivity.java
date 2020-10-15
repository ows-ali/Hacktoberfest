package com.example.musicplayerapp;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.RelativeLayout;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        RelativeLayout main_parent = findViewById(R.id.main_rel);
        RelativeLayout library = findViewById(R.id.library);
        RelativeLayout explore = findViewById(R.id.explore);
        RelativeLayout premium = findViewById(R.id.premium);

        AnimationDrawable animationDrawable = (AnimationDrawable) main_parent.getBackground();

        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(2000);

        animationDrawable.start();

        library.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, MusicLibrary.class);
                startActivity(i);
            }
        });

        explore.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, ExploreMusic.class);
                i.putExtra("Song Selected", "Apocalypse");
                startActivity(i);
            }
        });

        premium.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(MainActivity.this, Premium.class);
                startActivity(i);
            }
        });

    }
}
