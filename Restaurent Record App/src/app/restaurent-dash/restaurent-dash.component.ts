import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder } from '@angular/forms';
import { ApiService } from '../shared/api.service';
import { RestaurentData } from './restaurent.model';

@Component({
  selector: 'app-restaurent-dash',
  templateUrl: './restaurent-dash.component.html',
  styleUrls: ['./restaurent-dash.component.css']
})
export class RestaurentDashComponent implements OnInit {

  formValue!: FormGroup;
  restaurantModelObj: RestaurentData = new RestaurentData();
  allRestaurantData: any;
  showAdd: boolean = false;
  showBtn: boolean = false;

  constructor(private formbuilder: FormBuilder, private api: ApiService) { }

  ngOnInit(): void {
    this.formValue = this.formbuilder.group({
      name: [''],
      email: [''],
      mobile: [''],
      address: [''],
      services: [''],
    });
    this.getAllData();
  }

  clickAddResto() {
    this.formValue.reset();
    this.showAdd = true;
    this.showBtn = false;
  }

  addRestaurant() {
    const newRestaurantData: RestaurentData = {

      id: 0, // Temporary value
      name: this.formValue.value.name,
      email: this.formValue.value.email,
      mobile: this.formValue.value.mobile,
      address: this.formValue.value.address,
      services: this.formValue.value.services
    };
  
    this.api.addRestaurant(newRestaurantData).subscribe(
      (res: any) => {
        console.log(res);
        alert("Restaurant Added Successfully");
        this.formValue.reset();
        let ref = document.getElementById('close');
        ref?.click();
  
        // Assuming the response contains the newly added restaurant's data including ID
        if (res.id) {
          newRestaurantData.id = res.id++; // Update the ID
        }
  
        // Add the new restaurant to the list
        this.allRestaurantData.push(newRestaurantData);
      },
      (err) => {
        console.log(err);
        alert("Restaurant Addition Failed!");
      }
    );
  }
  
  
  

  getAllData() {
    this.api.getRestaurants().subscribe(res => {
      this.allRestaurantData = res;
    }, err => {
      console.log(err);
    })
  }

  deleteResto(id: number) {
    this.api.deleteRestaurant(id).subscribe((res: any) => {
      console.log(res);
      alert("Restaurant Deleted Successfully");
      this.getAllData();
    })
  }

  onEditResto(data: any) {
    this.showAdd = true;
    this.showBtn = true;
    this.restaurantModelObj = data;
  }

  updateResto(){
    this.restaurantModelObj.name = this.formValue.value.name;
    this.restaurantModelObj.email = this.formValue.value.email;
    this.restaurantModelObj.mobile = this.formValue.value.mobile;
    this.restaurantModelObj.address = this.formValue.value.address;
    this.restaurantModelObj.services = this.formValue.value.services;

    this.api.updateRestaurant(this.restaurantModelObj.id,this.restaurantModelObj).subscribe((res: any) => {
      alert("Restaurant Updated Successfully");
      this.formValue.reset();
      let ref= document.getElementById('close');
      ref?.click();
      this.getAllData();
    })
  }
}
