package JavaRTL;

public class Null extends Any {
    public JavaRTL.Number plus(Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number plus(JavaRTL.Number other) {
        return new JavaRTL.Number(other);
    }
    public JavaRTL.String plus(JavaRTL.String other) {
        return new JavaRTL.String(this).plus(other);
    }
    public JavaRTL.Number plus(JavaRTL.Boolean other) {
        return new JavaRTL.Number(other);
    }
    public JavaRTL.Number plus(JavaRTL.Void other) {
        return new JavaRTL.Number(other);
    }

    public JavaRTL.Number minus(Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number minus(JavaRTL.Number other) {
        return new JavaRTL.Number(other);
    }
    public JavaRTL.Number minus(JavaRTL.Undefined other) {
        return new JavaRTL.Number(other);
    }

    public JavaRTL.Number mul(Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number mul(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number mul(JavaRTL.Undefined other) {
        return new JavaRTL.Number(other);
    }

    public JavaRTL.Number div(Null other) {
        return new JavaRTL.Number(java.lang.Double.NaN);
    }
    public JavaRTL.Number div(JavaRTL.Number other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number div(JavaRTL.Undefined other) {
        return new JavaRTL.Number(other);
    }

    public JavaRTL.Number uPlus() {
        return new JavaRTL.Number(+0);
    }
    public JavaRTL.Number uMinus() {
        return new JavaRTL.Number(-0);
    }

    public JavaRTL.Boolean less(Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Number other) {
        return (new JavaRTL.Number(this)).less(other);
    }
    public JavaRTL.Boolean less(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Boolean other) {
        return (new JavaRTL.Number(this)).less(new Number(other));
    }
    public JavaRTL.Boolean less(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean great(Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Number other) {
        return (new JavaRTL.Number(this)).great(other);
    }
    public JavaRTL.Boolean great(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean equal(Null other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean equal(JavaRTL.Number other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.String other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.Void other) {
        return new JavaRTL.Boolean(true);
    }

    public JavaRTL.Boolean notEqual(Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Number other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.String other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean lessEqual(Null other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Number other) {
        return (new JavaRTL.Number(this)).lessEqual(other);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.String other) {
        return (new JavaRTL.Number(this)).lessEqual(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Boolean other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean greatEqual(Null other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Number other) {
        return (new JavaRTL.Number(this)).greatEqual(other);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.String other) {
        return (new JavaRTL.Number(this)).greatEqual(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Boolean other) {
        return (new JavaRTL.Number(this)).greatEqual(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }

    @Override
    public java.lang.String toString() {
        return "null";
    }
}
