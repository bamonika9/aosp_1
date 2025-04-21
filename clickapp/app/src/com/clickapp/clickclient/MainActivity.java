package com.clickapp.clickclient;

import android.app.Activity;
import android.os.Bundle;
import android.os.ServiceManager;
import android.os.IBinder;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import android.hardware.click.IClickService;

public class MainActivity extends Activity {
    IClickService clickService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView valueView = findViewById(R.id.valueText);
        Button readBtn = findViewById(R.id.readButton);
        Button triggerBtn = findViewById(R.id.triggerButton);

        try {
            IBinder binder = ServiceManager.getService("android.hardware.click.IClickService/default");
            clickService = IClickService.Stub.asInterface(binder);
        } catch (Exception e) {
            Toast.makeText(this, "Service not found", Toast.LENGTH_SHORT).show();
        }

        readBtn.setOnClickListener(v -> {
            try {
                int val = clickService.readValue();
                valueView.setText("Value: " + val);
            } catch (Exception e) {
                valueView.setText("Error reading");
            }
        });

        triggerBtn.setOnClickListener(v -> {
            try {
                clickService.triggerClick();
                Toast.makeText(this, "Triggered", Toast.LENGTH_SHORT).show();
            } catch (Exception e) {
                Toast.makeText(this, "Error triggering", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
