package JavaRTL;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Console {

    public static JavaRTL.Undefined log(Number value) {
        System.out.println(value.toString());
        return new Undefined();
    }

    public static JavaRTL.Undefined log(JavaRTL.String value) {
        System.out.println(value.toString());
        return new Undefined();
    }

    public static JavaRTL.Undefined log(JavaRTL.Boolean value) {
        System.out.println(value.toString());
        return new Undefined();
    }

    public static JavaRTL.Undefined log(JavaRTL.Null value) {
        System.out.println(value.toString());
        return new Undefined();
    }

    public static JavaRTL.Undefined log(JavaRTL.Undefined value) {
        System.out.println(value.toString());
        return new Undefined();
    }

    public static JavaRTL.Undefined log(JavaRTL.Void value) {
        // NOTE in normal way Void must not be printable. If this code print void - smth broken
        System.out.println(value.toString());
        return new Undefined();
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
