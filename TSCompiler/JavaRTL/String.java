package JavaRTL;

public class String extends Any {

    public java.lang.String _value;

    public String(java.lang.String value){
        this._value = value;
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
