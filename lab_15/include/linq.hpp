#ifndef LAB_15_LINQ_HPP
#define LAB_15_LINQ_HPP

#include <utility>
#include <vector>

namespace linq {
    namespace impl {

        template<typename T, typename Iter>
        class range_enumerator;
        template<typename T>
        class drop_enumerator;
        template<typename T, typename U, typename F>
        class select_enumerator;
        template<typename T, typename F>
        class until_enumerator;
        template<typename T>
        class take_enumerator;
        template<typename T, typename F>
        class where_enumerator;


        template<typename T>
        class enumerator {
        public:
            virtual const T& operator*() = 0; // Получает текущий элемент.
            virtual enumerator<T>& operator++() = 0;  // Переход к следующему элементу
            virtual explicit operator bool() = 0;  // Возвращает true, если есть текущий элемент

            auto drop(size_t count) {
                return impl::drop_enumerator<T>(*this, count);
            }

            auto take(size_t count) {
                return impl::take_enumerator<T>(*this, count);
            }

            template<typename U = T, typename F>
            auto select(F func) {
                return impl::select_enumerator<U, T, F>(*this, func);
            }

            template<typename F>
            auto until(F func) {
                return impl::until_enumerator<T, F>(*this, func);
            }

            auto until_eq(const T &x) {
                return this->until([x](const T &n){ return x == n;});
            }

            template<typename F>
            auto where(F func) {
                return impl::where_enumerator<T, F>(*this, func);
            }

            auto where_eq(const T &x) {
                auto f = [x](const T &n){ return x != n;};
                return this->where(f);
            }

            std::vector<T> to_vector() {
                std::vector<T> res;
                this->copy_to(std::back_inserter(res));
                return res;
            }

            template<typename Iter>
            void copy_to(Iter it) {
                while (static_cast<bool>(*this)) {
                    if(&*(*this) == null_element_)
                        break;
                    *it = *(*this);
                    ++it;
                    ++(*this);
                }
            }

        protected:
            T *null_element_ = nullptr;
        };

        template<typename T, typename Iter>
        class range_enumerator : public enumerator<T> {
        public:
            range_enumerator(Iter begin, Iter end) : begin_(begin), end_(end) {}

            virtual const T& operator*() override {
                return *begin_;
            }

            virtual enumerator<T>& operator++() override {
                ++begin_;
                return *this;
            }

            explicit operator bool() override {
                return begin_ != end_;
            }

        private:
            Iter begin_, end_;
        };

        template<typename T>
        class drop_enumerator : public enumerator<T> {
        public:
            drop_enumerator(enumerator<T> &parent, size_t count) : parent_(parent),
                                                                   count_(count),
                                                                   curr_count_(0)
                                                                   {}

            virtual const T& operator*() override {
                while(curr_count_ < count_ && static_cast<bool>(*this))
                    ++(*this);
                if(!static_cast<bool>(*this)) return *(enumerator<T>::null_element_);
                return *parent_;
            }

            virtual enumerator<T>& operator++() override {
                ++parent_;
                ++curr_count_;
                return *this;
            }

            explicit operator bool() override {
                return static_cast<bool>(parent_);
            }
        private:
            enumerator<T> &parent_;
            size_t count_;
            size_t curr_count_;
        };

        template<typename T, typename U, typename F>
        class select_enumerator : public enumerator<T> {
        public:
            select_enumerator(enumerator<U> &parent, F func) : parent_(parent),
                                                               func_(func)
                                                               {}

            virtual const T& operator*() override {
                element_ = func_(*parent_);
                return element_;
            }

            virtual enumerator<T>& operator++() override {
                ++parent_;
                return *this;
            }

            virtual explicit operator bool() override {
                return static_cast<bool>(parent_);
            }

        private:
            enumerator<U> &parent_;
            F func_;
            T element_;
        };

        template<typename T, typename F>
        class until_enumerator : public enumerator<T> {
        public:
            until_enumerator(enumerator<T> &parent, F &predicate) : parent_(parent),
                                                                    predicate_(predicate)
                                                                    {}

            virtual const T& operator*() override {
                return *parent_;
            }

            virtual enumerator<T>& operator++() override {
                ++parent_;
                return *this;
            }

            virtual explicit operator bool() override {
                return static_cast<bool>(parent_) && !predicate_(*parent_);
            }

        private:
            enumerator<T> &parent_;
            F predicate_;
        };

        template<typename T>
        class take_enumerator : public enumerator<T> {
        public:
            take_enumerator(enumerator<T> &parent, size_t count) : parent_(parent),
                                                                   count_(count)
                                                                   {}

            virtual const T& operator*() override {
                return *parent_;
            }

            virtual enumerator<T>& operator++() override {
                if (count_) {
                    --count_;
                    ++parent_;
                }
                return *this;
            }

            explicit operator bool() override {
                return static_cast<bool>(parent_) && count_;
            }

        private:
            enumerator<T> &parent_;
            size_t count_;
        };

        template<typename T, typename F>
        class where_enumerator : public enumerator<T> {
        public:
            where_enumerator(enumerator<T> &parent, F func) : parent_(parent),
                                                              func_(func),
                                                              is_curr_(static_cast<bool>(parent) && func(*parent))
                                                              {}
            virtual const T& operator*() override {;
                return *parent_;
            }

            virtual enumerator<T>& operator++() override {
                iter_correct();
                is_curr_ = static_cast<bool>(++parent_) && func_(*(parent_));
                return *this;
            }

            explicit operator bool() override {
                iter_correct();
                return static_cast<bool>(parent_);
            }
        private:
            enumerator<T> &parent_;
            F func_;
            bool is_curr_;

            void iter_correct() {
                while(!is_curr_ && static_cast<bool>(parent_))
                    is_curr_ = static_cast<bool>(++parent_) && func_(*(parent_));
            }

        };

    } // namespace impl

    template<typename Iter>
    auto from(Iter begin, Iter end) {
        return impl::range_enumerator<typename std::iterator_traits<Iter>::value_type , Iter>(begin, end);
    }

} // namespace linq

#endif //LAB_15_LINQ_HPP
