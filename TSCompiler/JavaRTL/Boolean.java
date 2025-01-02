package JavaRTL;

public class Boolean extends Any {
    public boolean _value;

    public int _ivalue;
    
    public Boolean(boolean value){
        this._value = value;
        this._ivalue = value == true;
    }

    public Boolean(int value) {
        this(value == true);
    }

    public Boolean(java.lang.String value) {
        this(value == true)
    }

    public Boolean equals(Boolean other) {
        return new Boolean(this._value == other._value);
    }

    public Boolean notEquals(Boolean other) {
        return new Boolean(this._value != other._value);
    }

    public Boolean not() {
        return new Boolean(!this._value);
    }

    public Boolean or(Boolean other) {
        return new Boolean(this._value || other._value);
    }

    public Boolean and(Boolean other) {
        return new Boolean(this._value && other._value);
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
