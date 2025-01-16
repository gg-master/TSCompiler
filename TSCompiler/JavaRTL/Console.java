package JavaRTL;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.Arrays;

public class Console {

    public static JavaRTL.Void log(java.lang.String value) {
        System.out.println(value);
        return new JavaRTL.Undefined();
    }

    public static JavaRTL.Void log(JavaRTL.Any value) {
        if (value == null) {
            System.out.println("undefined");
        } else {
            System.out.println(value.toString());
        }
        return new Undefined();
    }

    public static JavaRTL.Void log(JavaRTL.Any[] value) {
        return log(Arrays.toString(value));
    }

    public static JavaRTL.String readLine(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            java.lang.String s = br.readLine();
            return new JavaRTL.String(s);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
