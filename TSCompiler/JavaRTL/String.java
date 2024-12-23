package JavaRTL;

public class String {

    public java.lang.String _value;

    public String(java.lang.String value){
        this._value = value;
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
