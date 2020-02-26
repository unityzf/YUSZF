package com.dongnao.player;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class startActivity extends AppCompatActivity {
    EditText editText;
    Button start;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        editText=findViewById(R.id.text) ;
        start=findViewById(R.id.button) ;
        start.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                String inputText=editText.getText().toString();
                Intent intent = new Intent(startActivity.this, PlayActivity.class);
                intent.putExtra("url",inputText );
                startActivity(intent);
            }
        });

    }
}
