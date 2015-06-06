// (c) Copyright 2010,2011 Felipe Magno de Almeida
//
// This work is licensed under the Creative Commons
// Attribution-NonCommercial-NoDerivs 3.0 License.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/
// or send a letter to:
//      Creative Commons
//      171 2nd Street, Suite 300
//      San Francisco, California, USA.

package br.com.ghtv.android_opengl_player;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class GHTVActivity extends Activity {
    private OnClickListener open_ncl_listener
        = new OnClickListener()
            {
                public void onClick(View v)
                {
                    
                }
            };

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        setContentView(R.layout.main);
        Button open_ncl = (Button) findViewById(R.id.open_ncl);
        open_ncl.setOnClickListener(open_ncl_listener);
    }

    @Override protected void onPause() {
        super.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
    }
}
