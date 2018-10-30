package com.example.deepanshu.booklistingapp.custom;

import android.content.Context;
import android.graphics.Typeface;
import android.support.v7.widget.AppCompatTextView;
import android.util.AttributeSet;

/**
 * Created by foram on 20/2/17.
 */

public class Textview_lato_thin extends AppCompatTextView {

    public Textview_lato_thin(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init();
    }

    public Textview_lato_thin(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public Textview_lato_thin(Context context) {
        super(context);
        init();
    }

    private void init() {
        if (!isInEditMode()) {
            Typeface tf = Typeface.createFromAsset(getContext().getAssets(), "fonts/Lato-Regular.ttf");
            setTypeface(tf);
        }
    }

}
