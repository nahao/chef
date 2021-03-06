#ifndef _CHEF_BASE_BUFFER_H_
#define _CHEF_BASE_BUFFER_H_

#include <stdint.h>

class buffer
{
public:
    buffer(uint64_t init_capacity = 16384, uint64_t shrink_capacity = 1048576);
    ~buffer();

    //pull out
    char *read_pos() const {return data_ + read_index_;}
    uint64_t readable() const {return write_index_ - read_index_;}
    void erase(uint64_t len);

    //append1
    void reserve(uint64_t len);
    char *write_pos() const {return data_ + write_index_;}
    void seek_write(uint64_t len) {write_index_ += len;}
    //or just
    void append(const char *buf, uint64_t len);

    void reset(); 

    uint64_t capacity() const {return capacity_;}

#ifdef CHEF_UNIT_TEST
    uint64_t init_capacity() const {return init_capacity_;}
    uint64_t shrink_capacity() const {return shrink_capacity_;}
    uint64_t read_index() const {return read_index_;}
    uint64_t write_index() const {return write_index_;}
    char *data() const {return data_;}
#endif //CHEF_UNIT_TEST

private:
    const uint64_t init_capacity_;
    const uint64_t shrink_capacity_;
    uint64_t capacity_;
    uint64_t read_index_;
    uint64_t write_index_;
    char *data_;
};

#endif

