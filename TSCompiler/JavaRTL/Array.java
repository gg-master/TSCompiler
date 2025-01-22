package JavaRTL;

import java.util.Arrays;


public class Array extends Any {
    private Any[] _value = new Any[0];

    public Array() {}

    public Array(int length) {
        this._value = new Any[length];
    }

    public Array(Any[] value) {
        this._value = value;
    }

    // public Any get(Number index) {
    //     try {
    //         return this._value[index.toInt()];
    //     } catch (ArrayIndexOutOfBoundsException e) {
    //         return new Undefined();
    //     }
    // }
    public Any get(int index) {
        try {
            if (index < 0 || index >= _value.length) {
                return new Undefined();
            }
            return this._value[index];
        } catch (ArrayIndexOutOfBoundsException e) {
            return new Undefined();
        }
    }

    // public Any set(Number index, Any value) {
    //     try {
    //         this._value[index.toInt()] = value;
    //         return value;
    //     } catch (ArrayIndexOutOfBoundsException e) {
    //         return new Undefined();
    //     }
    // }

    public Any set(int index, Any value) {
        try {
            if (index < 0) {
                return value;
            }
            if (index >= _value.length) {
                for (int i = _value.length; i <= index; i++) {
                    this.push(new Undefined());
                }
            }
            this._value[index] = value;
            return value;
        } catch (ArrayIndexOutOfBoundsException e) {
            return new Undefined();
        }
    }

    public Any push(Any value) {
        Any[] newArray = new Any[this._value.length + 1];
        for (int i = 0; i < this._value.length; i++) {
            newArray[i] = this._value[i];
        }
        newArray[this._value.length] = value;
        this._value = newArray;
        return new Number(this._value.length);
    }

    public Any pop() {
        Any[] newArray = new Any[this._value.length - 1];
        for (int i = 0; i < this._value.length - 1; i++) {
            newArray[i] = this._value[i];
        }
        Any result = this._value[this._value.length - 1];
        this._value = newArray;
        return result;
    }

    public Any length() {
        return new Number(this._value.length);
    }

    @Override
    public java.lang.String toString() {
        java.lang.String str = Arrays.toString(this._value);
        return str.substring(1, str.length() - 1);
    }
}
