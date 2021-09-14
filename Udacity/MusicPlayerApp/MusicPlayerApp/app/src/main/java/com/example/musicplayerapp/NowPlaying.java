package com.example.musicplayerapp;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class NowPlaying extends AppCompatActivity {

    MediaPlayer mediaPlayer;
    TextView songName;
    Boolean isPlaying = true;
    ImageView playButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_now_playing);

        RelativeLayout now_playing_parent = findViewById(R.id.now_playing_rel);
        songName = findViewById(R.id.song_name);
        playButton = findViewById(R.id.play);
        AnimationDrawable animationDrawable = (AnimationDrawable) now_playing_parent.getBackground();

        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(2000);

        animationDrawable.start();

        Intent intent = getIntent();
        String song_name = intent.getStringExtra("Song Selected");
        songName.setText(song_name);

        switch (song_name)
        {
            case "Apocalypse" :
                mediaPlayer = MediaPlayer.create(NowPlaying.this, R.raw.apocalypse);
                break;

            case "Can't Help Falling" :
                mediaPlayer = MediaPlayer.create(NowPlaying.this, R.raw.cant_help);
                break;

            case "Coffee Shop" :
                mediaPlayer = MediaPlayer.create(NowPlaying.this, R.raw.coffee_shop);
                break;

            case "La Vie En Rose" :
                mediaPlayer = MediaPlayer.create(NowPlaying.this, R.raw.la_view_en_rose);
                break;

            case "The One" :
                mediaPlayer = MediaPlayer.create(NowPlaying.this, R.raw.the_one);
                break;

            default :
                mediaPlayer = null;
                break;
        }
        mediaPlayer.start();

        playButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isPlaying)
                {
                    isPlaying = false;
                    playButton.setImageResource(R.drawable.ic_play_arrow_black_24dp);
                    mediaPlayer.pause();
                }
                else {
                    isPlaying = true;
                    playButton.setImageResource(R.drawable.ic_pause_black_24dp);
                    mediaPlayer.start();
                }
            }
        });
    }

    @Override
    protected void onPause() {
        super.onPause();
        mediaPlayer.pause();
    }
    @Override
    protected void onResume() {
        super.onResume();
        if ( mediaPlayer != null)
            mediaPlayer.start();
    }
}
