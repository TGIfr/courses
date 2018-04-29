public class Variable<T> {

    private T _value;
    private Class<T> _type;

    public Variable(T value, Class<T> type) {
        this._value = value;
        this._type = type;
    }

    public Variable setSign() {
        if (_type.equals(Double.class)) {
            return new Variable<>(((Double) this._value) * -1, Double.class);
        }
        return this;
    }

    public T getValue() {
        return _value;
    }

    public void setValue(T _value) {
        this._value = _value;
    }

    public Class<T> getValueType() {
        return _type;
    }

    @Override
    public String toString() {
        return String.valueOf(_value);
    }

}
