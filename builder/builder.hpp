#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include <iostream>
#include <memory>

class Plane {
    public:
        void SetType(const std::string& type) { type_ = type; }
        void SetEngine(const std::string& engine) { engine_ = engine; }
        void SetVendor(const std::string& vendor) { vendor_ = vendor; }
        void SetModelName(const std::string& model_name) { model_ = model_name;}
        void See() const {
            std::cout << model_ << ":" << std::endl;
            std::cout << "Plane's Vendor is " << vendor_ << ", with "
            << engine_ << " engine, " << type_ << "type." << std::endl;
        }
    private:
        std::string type_;
        std::string engine_;
        std::string vendor_;
        std::string model_;
};

class PlaneBuilder {
    public:
        virtual ~PlaneBuilder() = default;
        void CreatePlane() {
            plane_ = std::make_unique<Plane>();
        }
        Plane* GetPlane() { return plane_.get(); }
        virtual void SelectType() = 0;
        virtual void SelectEngineType() = 0;
        virtual void SelectVendor() = 0;
        virtual void SelectModel() = 0;
    protected:
        std::unique_ptr<Plane> plane_;
};

class F18 : public PlaneBuilder{
    public:
        ~F18() override = default;
        virtual void SelectType() override {
            plane_->SetType("Fighter ");
        }
        virtual void SelectEngineType() override {
            plane_->SetEngine("Jet");
        }
        virtual void SelectVendor() override {
            plane_->SetVendor("Boeing");
        }
        virtual void SelectModel() override {
            plane_->SetModelName("F-18");
        }
}; 

class A320 : public PlaneBuilder {
    public:
        ~A320() override = default;
        virtual void SelectType() override {
            plane_->SetType("Airliner ");
        }
        virtual void SelectEngineType() override {
            plane_->SetEngine("Turbo Fan");
        }
        virtual void SelectVendor() override {
            plane_->SetVendor("Airbus");
        }
        virtual void SelectModel() override {
            plane_->SetModelName("A320");
        }
};

class Consumer {
    public:
        void SeePlane() { builder->GetPlane()->See(); }
        void ProducePlane(PlaneBuilder *pb) {
            builder = pb;
            builder->CreatePlane();
            builder->SelectType();
            builder->SelectEngineType();
            builder->SelectVendor();
            builder->SelectModel();
        }
    private:
        PlaneBuilder *builder;
};

#endif // BUILDER_HPP_