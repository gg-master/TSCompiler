package JavaRTL;

public class String extends Any {

    public java.lang.String _value = "";

    public String() {}

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
        if (value == null) {
            this._value = "undefined";
            return;
        }
        this._value = value.toString();
    }

    public String plus(JavaRTL.Any other) {
        return new String(this._value + (new String(other))._value);
    }

    public JavaRTL.Number uPlus() {
        return new JavaRTL.Number(this._value);
    }
    public JavaRTL.Number uMinus() {
        return new JavaRTL.Number(this._value);
    }

    public JavaRTL.Boolean less(String other) {
        boolean result = this._value.compareTo(other._value) < 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean less(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).less(new Number(other));
    }
    public JavaRTL.Boolean less(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean great(String other) {
        boolean result = this._value.compareTo(other._value) > 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean great(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).great(new Number(other));
    }
    public JavaRTL.Boolean great(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean equal(String other) {
        boolean result = this._value.compareTo(other._value) == 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean equal(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).equal(new Number(other));
    }
    public JavaRTL.Boolean equal(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean notEqual(String other) {
        boolean result = this._value.compareTo(other._value) != 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).notEqual(new Number(other));
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(true);
    }

    public JavaRTL.Boolean lessEqual(String other) {
        boolean result = this._value.compareTo(other._value) <= 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).lessEqual(new Number(other));
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean greatEqual(String other) {
        boolean result = this._value.compareTo(other._value) >= 0 ? true : false;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).greatEqual(new Number(other));
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
