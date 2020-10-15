package com.example.musicplayerapp;

import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.widget.RelativeLayout;

import androidx.appcompat.app.AppCompatActivity;

public class Premium extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_premium);

        RelativeLayout premium_parent = findViewById(R.id.premium_rel);
        AnimationDrawable animationDrawable = (AnimationDrawable) premium_parent.getBackground();

        animationDrawable.setEnterFadeDuration(2000);
        animationDrawable.setExitFadeDuration(2000);

        animationDrawable.start();
    }
}
