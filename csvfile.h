#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Row
{

    vector<string> _values;

public:

    Row(const vector<string> &row);
    ~Row();

    /// Get value, else throw error
    const string getValue(size_t pos) const;
    const string operator[](size_t pos) const;


    /// Get size of row
    size_t size() const;

    /// Add new column in row
    void push(const string& pushString);
    /// Set data to specified pos
    bool set(size_t pos, const string& value);
};

class CSVFile
{

    string _fileName;
    const char _sep;
    vector<Row> _content;

public:
    /// Constructs parser and parse specified file
    CSVFile(const string &fileName, char sep = ';');
    /// Save
    ~CSVFile();

    /// Get row by index, else throw error
    Row getRow(size_t row) const;
    /// Get value by specified row and column
    string getValue(size_t row, size_t column) const;
    /// Set value by specified row and column
    void setValue(size_t row, size_t column, string string);
    /// Get row count
    size_t rowCount() const;
    /// Get column count
    size_t columnCount() const;

    void save(string new_string);
    void NewRow();
    void NewColumn();

    /// Get name of parsed file
    const string& getFileName() const;

    bool deleteRow(size_t row);
    bool addRow(Row &row);
    bool addRow(const vector<string>& arr);

};
