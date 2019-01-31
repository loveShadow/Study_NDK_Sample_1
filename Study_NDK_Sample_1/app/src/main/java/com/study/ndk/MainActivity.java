package com.study.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("sum");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.testBtn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NDKDemo.sum(3, 5);

                int result = NDKDemo.mult(7);
                Log.d("ZHAOLI", "result = " + result);
            }
        });
    }
}
