#pragma once

template <typename TypeDataToSave>
class SaveData {
public:
    virtual bool save() = 0;
    virtual bool read() = 0;

    inline void datas(const TypeDataToSave& datas) {
        this->m_datas = datas;
    }

    inline const TypeDataToSave& datas() const {
        return this->m_datas;
    }
private:
    TypeDataToSave m_datas;
};