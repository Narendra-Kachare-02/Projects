import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { map } from 'rxjs/operators';
import { RestaurentData } from '../restaurent-dash/restaurent.model'; // assuming you have a file called restaurant.model.ts


@Injectable({
  providedIn: 'root'
})
export class ApiService {
  postRestaurent(restaurantModelObj: RestaurentData) {
    throw new Error('Method not implemented.');
  }
  constructor(private _http: HttpClient) {}

  // POST request to add a new restaurant
  addRestaurant(restaurantModelObj: RestaurentData) {
    return this._http.post<any>('http://localhost:3000/posts', restaurantModelObj).pipe(
      map((res: any) => {
        return res;
      })
    );
  }

  // GET request to fetch all restaurants
  getRestaurants() {
    return this._http.get<any>('http://localhost:3000/posts').pipe(
      map((res: any) => {
        return res;
      })
    );
  }

  // DELETE request to delete a restaurant by ID
  deleteRestaurant(id: number) {
    return this._http.delete<any>('http://localhost:3000/posts/' + id).pipe(
      map((res: any) => {
        return res;
      })
    );
  }

  // PUT request to update a restaurant by ID
  updateRestaurant(id: number, data: any) {
    return this._http.put<any>('http://localhost:3000/posts/' + id, data).pipe(
      map((res: any) => {
        return res;
      })
    );
  }
}
