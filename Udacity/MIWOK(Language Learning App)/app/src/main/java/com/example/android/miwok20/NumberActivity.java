package com.example.android.miwok20;
import androidx.appcompat.app.AppCompatActivity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import java.util.ArrayList;

public class NumberActivity extends AppCompatActivity {

    private MediaPlayer mMediaPlayer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.word_list);

        //Adding ArrayList of Strings.
        final ArrayList<Word> words = new ArrayList<Word>();
        words.add(new Word("one", "lutti", R.drawable.number_one,R.raw.number_one));
        words.add(new Word("two", "otiiko", R.drawable.number_two,R.raw.number_two));
        words.add(new Word("three", "tolookosu", R.drawable.number_three,R.raw.number_three));
        words.add(new Word("four", "oyyisa", R.drawable.number_four,R.raw.number_four));
        words.add(new Word("five", "massokka", R.drawable.number_five, R.raw.number_five));
        words.add(new Word("six", "temmokka", R.drawable.number_six, R.raw.number_six));
        words.add(new Word("seven", "kenekaku", R.drawable.number_seven, R.raw.number_seven));
        words.add(new Word("eight", "kawinta", R.drawable.number_eight, R.raw.number_eight));
        words.add(new Word("nine", "wo'e", R.drawable.number_nine, R.raw.number_nine));
        words.add(new Word("ten", "na'achcha", R.drawable.number_ten, R.raw.number_ten));


//        Using a while loop to display words.
//         int index = 0;
//        LinearLayout rootView = (LinearLayout) findViewById(R.id.rootView);
//        while (index < words.size()) {
//            TextView word_view = new TextView(this);
//            word_view.setText(words.get(index));
//            rootView.addView(word_view);
//            index++;
//
//        Using for loop.
//        Using ListView and ArrayAdapter we would decrease the use of RAM.
//        for (int index = 0; index < words.size(); index++) {
//            TextView word_view = new TextView(this);
//            word_view.setText(words.get(index));
//            rootView.addView(word_view);

        //Using ListView and ArrayAdapter.
//        ArrayAdapter<Word> itemsAdapter = new ArrayAdapter<Word>(this, android.R.layout.activity_list_item, words);
//        ListView listView = (ListView) findViewById(R.id.list);
//        listView.setAdapter(itemsAdapter);

        //Using Custom Array Adapter.
        WordAdapter wordsAdapter = new WordAdapter(this, words, R.color.category_numbers);
        ListView numberView = findViewById(R.id.list);
        numberView.setAdapter(wordsAdapter);

        // Set a click listener to play the audio when the list item is clicked on
        numberView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                Word word = words.get(position);
                mMediaPlayer = MediaPlayer.create(NumberActivity.this, word.getAudioResourceId());
                mMediaPlayer.start();
            }
        });
    }
}
