package JavaRTL;

public class String extends Any {

    public java.lang.String _value;

    public String(int value){
        this._value = java.lang.String.valueOf(value);
    }

    public String(double value){
        this._value = java.lang.String.valueOf(value);
    }

    public String(java.lang.String value){
        this._value = value;
    }

    public String(JavaRTL.Any value){
        this._value = value.toString();
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
