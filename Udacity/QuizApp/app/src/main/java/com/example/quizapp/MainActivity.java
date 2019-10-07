package com.example.quizapp;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button yesButton, noButton, trueButton, falseButton;
    TextView quesTextview;
    LinearLayout quizButtons;
    String[] questions = new String[10];
    int noOfQues = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        yesButton = findViewById(R.id.yes_button);
        noButton = findViewById(R.id.no_button);
        quesTextview = findViewById(R.id.question);
        quizButtons = findViewById(R.id.quiz_btns);
        trueButton = findViewById(R.id.true_button);
        falseButton = findViewById(R.id.false_button);
        quizButtons.setVisibility(View.GONE);

        //add questions
        questions[0] = getString(R.string.ques1);
        questions[1] = getString(R.string.ques2);
        questions[2] = getString(R.string.ques3);
        questions[3] = getString(R.string.ques4);
        questions[4] = getString(R.string.ques5);

        //if yes, start asking the ques
        yesButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                yesButton.setVisibility(View.GONE);
                noButton.setVisibility(View.GONE);
                quizButtons.setVisibility(View.VISIBLE);
                quesTextview.setText(questions[noOfQues]);
            }
        });

        noButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                quesTextview.setText(R.string.later);
                yesButton.setVisibility(View.GONE);
                noButton.setVisibility(View.GONE);
            }
        });

        //take ans input as true/false.
        trueButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                noOfQues++;
                if (noOfQues == 5) {
                    quizButtons.setVisibility(View.GONE);
                    quesTextview.setText(R.string.thanks);
                }
                else quesTextview.setText(questions[noOfQues]);
            }
        });

        falseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                noOfQues++;
                if (noOfQues == 5) {
                    quizButtons.setVisibility(View.GONE);
                    quesTextview.setText(R.string.thanks);
                }
                else quesTextview.setText(questions[noOfQues]);
            }
        });
    }
}
